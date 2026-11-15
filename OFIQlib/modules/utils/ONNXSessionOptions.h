/**
 * @file ONNXSessionOptions.h
 *
 * @copyright Copyright (c) 2026  Federal Office for Information Security, Germany
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @brief Shared ONNX Runtime session options for configurable threading.
 * @author OFIQ development team
 */

#pragma once

#include "Configuration.h"
#include "OFIQError.h"
#include "RuntimeThreadSettings.h"

#include <iostream>
#include <onnxruntime_cxx_api.h>
#include <string>
#include <unordered_map>

namespace OFIQ_LIB
{
    /**
     * @brief Returns a shared process-wide ONNX Runtime environment instance.
     * @return Reference to the shared Ort::Env singleton.
     */
    inline Ort::Env& GetSharedOrtEnv()
    {
        static Ort::Env sharedEnv(ORT_LOGGING_LEVEL_ERROR, "OFIQ");
        return sharedEnv;
    }

    /**
     * @brief Resolves the effective ONNX Runtime execution provider name.
     * @param configuredProvider Normalized provider string from configuration.
     * @return Resolved concrete provider name (e.g., "cpu", "cuda", "coreml").
     */
    inline std::string ResolveOrtExecutionProvider(const std::string& configuredProvider)
    {
        if (configuredProvider != "auto")
            return configuredProvider;

#if defined(__APPLE__)
        return "coreml";
#elif defined(OFIQ_ORT_GPU_ENABLED)
        return "cuda";
#else
        return "cpu";
#endif
    }

    /**
     * @brief Appends the requested GPU execution provider to the given session options.
     * @param options Session options to modify.
     * @param provider Concrete execution provider name ("cuda", "tensorrt", "coreml", "dml", "rocm").
     * @param deviceId Target GPU device ID.
     * @param fallbackToCpu If true, logs a warning and falls back to CPU when registration fails.
     * @throws OFIQ_LIB::OFIQError if registration fails and fallbackToCpu is false.
     */
    inline void AppendOrtExecutionProvider(
        Ort::SessionOptions& options,
        const std::string& provider,
        int deviceId,
        bool fallbackToCpu)
    {
        if (provider == "cpu")
            return;

        try
        {
            if (provider == "cuda")
            {
                OrtCUDAProviderOptions cudaOptions{};
                cudaOptions.device_id = deviceId;
                options.AppendExecutionProvider_CUDA(cudaOptions);
            }
            else if (provider == "tensorrt")
            {
                OrtTensorRTProviderOptions trtOptions{};
                trtOptions.device_id = deviceId;
                options.AppendExecutionProvider_TensorRT(trtOptions);
            }
            else if (provider == "rocm")
            {
                OrtROCMProviderOptions rocmOptions{};
                rocmOptions.device_id = deviceId;
                options.AppendExecutionProvider_ROCM(rocmOptions);
            }
            else if (provider == "coreml")
            {
                std::unordered_map<std::string, std::string> coremlOptions;
                options.AppendExecutionProvider("CoreML", coremlOptions);
            }
            else if (provider == "dml")
            {
                std::unordered_map<std::string, std::string> dmlOptions{
                    {"device_id", std::to_string(deviceId)}};
                options.AppendExecutionProvider("DML", dmlOptions);
            }
        }
        catch (const Ort::Exception& e)
        {
            if (fallbackToCpu)
            {
                std::cerr << "[OFIQ] Warning: Failed to enable ONNX Runtime execution provider '"
                          << provider << "' on device " << deviceId << " (" << e.what()
                          << "). Falling back to CPU execution provider." << std::endl;
            }
            else
            {
                throw OFIQError(
                    OFIQ::ReturnCode::UnknownError,
                    "Failed to enable ONNX Runtime execution provider '" + provider +
                        "' on device " + std::to_string(deviceId) + ": " + e.what());
            }
        }
    }

    /**
     * @brief Creates ONNX Runtime session options from the JAXN configuration.
     * @param config Configuration instance.
     * @return Session options configured with
     * <code>ort_intra_threads</code>, <code>ort_inter_threads</code>,
     * <code>ort_run_parallel</code>, and any requested GPU execution provider.
     */
    inline Ort::SessionOptions CreateONNXSessionOptions(const Configuration& config)
    {
        Ort::SessionOptions options;
        const unsigned int intraThreadCount = RuntimeThreadSettings::GetOrtIntraThreadCount(config);
        const unsigned int interThreadCount = RuntimeThreadSettings::GetOrtInterThreadCount(config);
        if (const bool runParallel = RuntimeThreadSettings::GetOrtRunParallel(config))
            options.SetExecutionMode(ExecutionMode::ORT_PARALLEL);
        else
            options.SetExecutionMode(ExecutionMode::ORT_SEQUENTIAL);
        
        if (intraThreadCount > 0)
            options.SetIntraOpNumThreads(static_cast<int>(intraThreadCount));
        if (interThreadCount > 0)
            options.SetInterOpNumThreads(static_cast<int>(interThreadCount));

        const std::string configuredProvider = RuntimeThreadSettings::GetOrtExecutionProvider(config);
        const int deviceId = RuntimeThreadSettings::GetOrtDeviceId(config);
        const bool fallbackToCpu = RuntimeThreadSettings::GetOrtFallbackToCpu(config);
        const std::string resolvedProvider = ResolveOrtExecutionProvider(configuredProvider);

        AppendOrtExecutionProvider(options, resolvedProvider, deviceId, fallbackToCpu);

        return options;
    }
}
