# Compilation

To build OFIQ you need to install Python with pip, cmake and conan.

- Python (version 3.10.12 or higher)
- [Download and install cmake](https://cmake.org/) (version 3.26 or higher)
- [Download and install conan](https://conan.io/) (version 2.18.1)

## Linux

### Ubuntu 22.04 (x86_64)

Install necessary packages.

```
sudo apt-get install build-essential python3-pip
```

To install cmake (in a version 3.26) use snap (and not apt) as follows.

```
sudo snap install cmake --channel=3.26/stable --classic
```

Conan can be installed via Python with

```
pip install conan==2.18.1
```

In some cases the command above shows a warning *"Defaulting to user installation because normal site-packages is not writeable"*, to avoid this you can pass a `--user` argument:

```
pip install --user conan==2.18.1
```

The conan binary will be installed in `$HOME/.local/bin` and this path will be added to your `~/.profile` file. You'll need to relogin or rload the `.profile` with

```
source ~/.profile
```

In order to build OFIQ and installing all required packages via conan run the following.

```
cd path/to/OFIQ_Project/scripts
sh build.sh
```

where `path/to/OFIQ_Project/` denotes the root folder of the OFIQ source files.

This will create the following output.
<table>
 <tr>
  <td><b>file/directory</b></td>
  <td><b>description</b></td>
 </tr>
 <tr>
  <td>build/</td>
  <td>Folder with the Linux build including the binaries <code>OFIQSampleApp</code> and <code>libofiq_lib.so</code>.</td>
 </tr>
 <tr>
  <td>build/conan/</td>
  <td>Conan cache with packages downloaded.</td>
 </tr>
 <tr>
  <td>install_x86_64_linux/</td>
  <td>Folder with the installation including the binaries <code>Release/bin/OFIQSampleApp</code>,
   <code>Release/lib/libofiq_lib.so</code>, <code>Release/lib/libonnxruntime.so.1.18.1</code>, and the
   header files in <code>Release/include/</code>. </td>
 </tr>
 <tr>
  <td>data/models/</td>
  <td>Model files downloaded from the ISO portal or eu-LISA during build process.</td>
 </tr>
 <tr>
  <td>data/tests/images/</td>
  <td>Conformance test images downloaded from the ISO portal or eu-LISA.</td>
 </tr>
</table>

### Ubuntu 24.04 (x86_64)

Install necessary packages.

```
sudo apt-get install build-essential python3-pip cmake python3.12-venv
```

To install conan, a virtual Python environment needs to be generated first.

```
python3 -m venv path/to/py_ofiq_env
```

where `path/to/py_ofiq_env` is the path where the python environment will be stored
and `py_ofiq_env` is the name of the new environment.

Then install conan as follows.

```
source path/to/py_ofiq_env/bin/activate
pip install conan==2.18.1
```

In order to build OFIQ and installing all required packages via conan run the following.

```
source path/to/py_ofiq_env/bin/activate
cd path/to/OFIQ_Project/scripts
sh build.sh
```

where `path/to/OFIQ_Project/` denotes the root folder of the OFIQ source files.

This will create the following output.
<table>
 <tr>
  <td><b>file/directory</b></td>
  <td><b>description</b></td>
 </tr>
 <tr>
  <td>build/</td>
  <td>Folder with the Linux build including the binaries <code>OFIQSampleApp</code> and <code>libofiq_lib.so</code>.</td>
 </tr>
 <tr>
  <td>build/conan/</td>
  <td>Conan cache with packages downloaded.</td>
 </tr>
 <tr>
  <td>install_x86_64_linux/</td>
  <td>Folder with the installation including the binaries <code>Release/bin/OFIQSampleApp</code>,
   <code>Release/lib/libofiq_lib.so</code>, <code>Release/lib/libonnxruntime.so.1.18.1</code>, and the
   header files in <code>Release/include/</code>. </td>
 </tr>
 <tr>
  <td>data/models/</td>
  <td>Model files downloaded from the ISO portal during build process.</td>
 </tr>
 <tr>
  <td>data/tests/images/</td>
  <td>Conformance test images downloaded from the ISO portal.</td>
 </tr>
</table>

### Ubuntu 24.04 (Raspberry Pi/ARMv8)

The following has been tested on a Raspberry Pi5 with 4GB RAM.

Install necessary packages.

```
sudo apt-get install build-essential python3-pip cmake python3.12-venv
```

To install conan, a virtual Python environment needs to be generated first.

```
python3 -m venv /path/to/py_ofiq_env
```

where `path/to/py_ofiq_env` is the path where the python environment will be stored
and `py_ofiq_env` is the name of the new environment.

Then install conan as follows.

```
source /path/to/py_ofiq_env/bin/activate
pip install conan==2.18.1
```

In order to build OFIQ and installing all required packages via conan run the following.

```
source /path/to/py_ofiq_env/bin/activate
cd /path/to/OFIQ_Project/scripts
sh build.sh --os linux-arm64
```

where `path/to/OFIQ_Project/` denotes the root folder of the OFIQ source files.

This will create the following output.

<table>
 <tr>
  <td><b>file/directory</b></td>
  <td><b>description</b></td>
 </tr>
 <tr>
  <td>build/</td>
  <td>Folder with the Linux build including the binaries <code>OFIQSampleApp</code> and <code>libofiq_lib.so</code>.</td>
 </tr>
 <tr>
  <td>build/conan/</td>
  <td>Conan cache with packages downloaded.</td>
 </tr>
 <tr>
  <td>install_arm64_linux/</td>
  <td>Folder with the installation including the binaries <code>Release/bin/OFIQSampleApp</code>,
   <code>Release/lib/libofiq_lib.so</code>, <code>Release/lib/libonnxruntime.so.1.18.1</code>, and the
   header files in <code>Release/include/</code>. </td>
 </tr>
 <tr>
  <td>data/models/</td>
  <td>Model files downloaded from the ISO portal during build process.</td>
 </tr>
 <tr>
  <td>data/tests/images/</td>
  <td>Conformance test images downloaded from the ISO portal.</td>
 </tr>
</table>

## Windows

### Windows (x86_64)

The following has been tested on a Windows 10 (64 bit) installation using a <b>Python installation version 3.11.5</b>
with pip package such that the <code>pip</code> command can be executed from the command prompt. Furthermore, an installation
of <b>cmake version 3.29</b> has been used. As the compiler, <b>Microsoft's Visual Studio 2019</b> was used.
<br/>
<br/>
To install conan, run

```
 pip install conan==2.18.1
```

from the command prompt.
<br/>
<br/>
In order to build OFIQ and install all required packages run the following.

```
cd C:\Path\To\OFIQ_Project\scripts
build.cmd
```

where `C:\Path\To\OFIQ-Project` denotes the root folder of the OFIQ source files.

This will create the following output.
<table>
 <tr>
  <td><b>directory</b></td>
  <td><b>description</b></td>
 </tr>
 <tr>
  <td>`build\build_win\`</td>
  <td>Folder with the Visual Studio solution files placed and pre-compilation.</td>
 </tr>
 <tr>
  <td>`build\conan\`</td>
  <td>Conan cache with packages downloaded.</td>
 </tr>
 <tr>
  <td>`install_x86_64\`</td>
  <td>
   Folder with the OFIQ installation files. This includes the binaries `Release\bin\OFIQSampleApp`,
   `Release\bin\libofiq_lib.so`, `Release\bin\libonnxruntime.so.1.18.1`, and the
   header files in `Release\include\`.
   </td>
 </tr>
 <tr>
  <td>`data\models\`</td>
  <td>Model files downloaded from the ISO portal during build process.</td>
 </tr>
 <tr>
  <td>`data\tests\images\`</td>
  <td>Conformance test images downloaded from the ISO portal.</td>
 </tr>
</table>

### Windows (x86)

To compile Win32 binaries, one proceeds in the same way as for x86_64 described above. But the building script
is run with the `--arch x86` argument:

```
cd C:\Path\To\OFIQ_Project\scripts\
build.cmd --arch x86
```

## MacOS

### MacOS (ARM64)

The following has been tested on `macOS Sonoma Version 14.4.1` with ARM64 processor.

Install Homebrew

```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Then update profiles

```
(echo; echo 'eval "$(/opt/homebrew/bin/brew shellenv)"') >> ~/.zprofile
eval "$(/opt/homebrew/bin/brew shellenv)"
```

where <code>/opt/homebrew/bin/brew</code> is the path to the homebrew executable and can vary among MacOS systems.
<br/><br/>
NOTE The two commands from above for updating profiles are output by the Homebrew installation script.
<br/><br/>
Install CMake.

```
brew install cmake
```

Install Python using Miniconda by

```
mkdir -p /path/to/miniconda3/
curl https://repo.anaconda.com/miniconda/Miniconda3-latest-MacOSX-arm64.sh -o /path/to/miniconda3/miniconda.sh
bash /path/to/miniconda3/miniconda.sh -b -u -p /path/to/miniconda3
rm -rf /path/to/miniconda3/miniconda.sh
/path/to/miniconda3/bin/conda init bash
/path/to/miniconda3/bin/conda init zsh
```

where <code>/path/to/miniconda3</code> can be replaced by the path where Miniconda is installed.
<br/><br/>
Install conan.

```
$ python -m pip install conan==2.18.1
```

Finally, to build OFIQ run the following.

```
 $ cd /path/to/OFIQ_Project/scripts/
 $ sh build.sh --os macos
```

### MacOS (x86_64)

To compile OFIQ on MacOS x86_64 one needs to
edit <code>/path/to/OFIQ_Project/conan/conan_profile_release_macos.txt</code>
and <code>/path/to/OFIQ_Project/conan/conan_profile_debug_macos.txt</code> first. In both files replace the line
<pre>
arch=armv8
</pre>
by
<pre>
arch=x86_64
</pre>
Then apply the same actions as for MacOS compilation on ARM64.

## Download model files

To run OFIQ, the model files from [the ISO portal](https://standards.iso.org/iso-iec/29794/-5/ed-1/en/OFIQ-MODELS.zip) (or  alternatively from the [eu-LISA](https://resources.eulisa.europa.eu/research/OFIQ-Models.zip)
need to be downloaded and be placed in the <code>./data/models/</code> directory so that the file structure matches the following.
<table>
 <tr><td>/path/to/OFIQ-Project/data/models/expression_neutrality/*</td></td>
 <tr><td>/path/to/OFIQ-Project/data/models/face_detection/*</td></td>
 <tr><td>/path/to/OFIQ-Project/data/models/face_landmark_estimation/*</td></td>
 <tr><td>/path/to/OFIQ-Project/data/models/face_occlusion_segmentation/*</td></td>
 <tr><td>/path/to/OFIQ-Project/data/models/face_parsing/*</td></td>
 <tr><td>/path/to/OFIQ-Project/data/models/head_pose_estimation/*</td></td>
 <tr><td>/path/to/OFIQ-Project/data/models/no_compression_artifacts/*</td></td>
 <tr><td>/path/to/OFIQ-Project/data/models/sharpness/*</td></td>
 <tr><td>/path/to/OFIQ-Project/data/models/unified_quality_score/*</td></td>
</table>
<br/><br/>
Here, <code>/path/to/OFIQ-Project/</code> denotes the path to OFIQ's root folder.
<br/><br/>
This step is integrated in the cmake building process.

## Download conformance test images

To run conformance tests, the conformance test
images need to be downloaded from
[the ISO portal](https://standards.iso.org/iso-iec/29794/-5/ed-1/en/OFIQ-IMAGES.zip) or (alternative from the [eu-LISA](https://resources.eulisa.europa.eu/research/OFIQ-ImagesConformanceTest+TargetValues.zip))
and be placed in the <code>./data/tests/images/</code> directory so that the file structure matches the following.
<table>
 <tr><td>/path/to/OFIQ-Project/data/tests/images/b-01-smile.png</td></td>
 <tr><td>...</td></td>
 <tr><td>/path/to/OFIQ-Project/data/tests/images/r-09-background.png</td></td>
</table>
<br/><br/>
Here, <code>/path/to/OFIQ-Project/</code> denotes the path to OFIQ's root folder. Download and extraction of conformance test images can be performed when running the cmake building process.

## Download of external libraries

The source of the external libraries that are used by OFIQ can be downloaded
along with a full OFIQ release from [eu-LISA](https://resources.eulisa.europa.eu/research/OFIQ-ExternalLibraryDependencies-v1.1.1.zip).
<br/><br>
To build OFIQ without conan (described below), we need to extract the archive so that file structure
matches the following:
<table>
 <tr><td>/path/to/OFIQ-Project/extern/flatbuffers/*</td></tr>
 <tr><td>/path/to/OFIQ-Project/extern/googletest/*</td></tr>
 <tr><td>/path/to/OFIQ-Project/extern/gzip-hpp/*</td></tr>
 <tr><td>/path/to/OFIQ-Project/extern/json/*</td></tr>
 <tr><td>/path/to/OFIQ-Project/extern/magic_enum/*</td></tr>
 <tr><td>/path/to/OFIQ-Project/extern/onnxruntime/*</td></tr>
 <tr><td>/path/to/OFIQ-Project/extern/openvc-4.5.5/*</td></tr>
 <tr><td>/path/to/OFIQ-Project/extern/PEGTL/*</td></tr>
</table>
Here, <code>/path/to/OFIQ-Project/</code> denotes the path to OFIQ's root folder.
<br/><br/>
Note, download and extraction of the external libraries can be done automatically by the cmake building process described below.

## Building without conan

To build OFIQ without conan, one can run

```
cd C:\Path\To\OFIQ-Project\scripts\
.\build.cmd --no-conan
```

on Windows or

```
cd /path/to/OFIQ-Project/scripts/
sh build.sh --no-conan
```

on Linux (both x86_64 and ARMv8) and MacOS. This will download and extract the model files, conformance test images, and external libraries from the ISO portal as described above.
<br/><br/>
To suppress download of the dependencies (e.g., when one wants to compile without an internet connection), one can run

```
cd C:\Path\To\OFIQ-Project\scripts\
.\build.cmd --no-conan --no-download
```

on Windows or

```
cd /path/to/OFIQ-Project/scripts/
sh build.sh --no-conan --no-download
```

on Linux and MacOS. 
<br /><br />
It is important to note that building without conan while suppressing download requires manual extraction of model files and external library dependencies (and perhaps conformance test images) before running the building scripts. Further note, the files have to be placed manually in the right directory as described above. The missing files can be downloaded along with the release archive available from [eu-LISA](https://resources.eulisa.europa.eu/research/OFIQ-PrecompiledBinaries.zip).
<br/><br/>

# Running conformance tests

The conformance tests are executed by going to <code>/path/to/OFIQ_Project/scripts/</code>
and run
 * <code>conformance_tests.cmd</code> (Windows).
 * <code>conformance_tests.sh</code> (Linux/x86_64).
 * <code>conformance_tests.sh --os linux-arm64</code> (Linux/ARMv8)
 * <code>conformance_tests.sh --os macos</code> (MacOS).

# GPU Support (Optional)

OFIQ can optionally build and run ONNX Runtime models using GPU Execution Providers (`cuda`, `tensorrt`, `coreml`, `dml`, `rocm`, or `auto`).

## Building with GPU support

Pass `--gpu` to the build scripts (or `-DOFIQ_USE_GPU=ON` directly to CMake):

```
cd /path/to/OFIQ_Project/scripts
sh build.sh --gpu
```

On Windows:

```
cd C:\Path\To\OFIQ_Project\scripts
build.cmd --gpu
```

### Linux (x86_64) with the CUDA provider

The build downloads a pre-compiled GPU package of ONNX Runtime from its GitHub releases
instead of the CPU package. Its release is the CMake cache variable `OFIQ_ORT_GPU_VERSION`
(default `1.20.1`), and that release decides which CUDA libraries the provider loads at run time:

<table>
 <tr><td><b>ONNX Runtime release</b></td><td><b>GPU package</b></td><td><b>needs at run time</b></td></tr>
 <tr><td>1.18.x</td><td><code>onnxruntime-linux-x64-gpu-1.18.x.tgz</code></td><td>CUDA 12 and cuDNN 8</td></tr>
 <tr><td>1.19 to 1.23</td><td><code>onnxruntime-linux-x64-gpu-&lt;version&gt;.tgz</code></td><td>CUDA 12 and cuDNN 9</td></tr>
 <tr><td>1.24 and later</td><td><code>onnxruntime-linux-x64-gpu-&lt;version&gt;.tgz</code> (CUDA 12) or <code>onnxruntime-linux-x64-gpu_cuda12-&lt;version&gt;.tgz</code> from 1.27 on; <code>onnxruntime-linux-x64-gpu_cuda13-&lt;version&gt;.tgz</code> (CUDA 13)</td><td>CUDA 12 and cuDNN 9, or CUDA 13 and cuDNN 9</td></tr>
</table>

`CMakeLists.txt` composes the package name as `onnxruntime-linux-x64-gpu-<version>.tgz`, so the
variable selects a CUDA 12 build of release 1.18.1 to 1.26.x; a `gpu_cuda12` or `gpu_cuda13` package
needs the file name in `CMakeLists.txt` and `OFIQlib/CMakeLists.ubuntu.cmake` changed as well.
The CUDA provider (`libonnxruntime_providers_cuda.so`) is linked against the CUDA libraries by
soname (for CUDA 12: `libcudart.so.12`, `libcublas.so.12`, `libcublasLt.so.12`, `libcufft.so.11`,
`libcurand.so.10`, `libnvrtc.so.12` and `libcudnn.so.9`), so any CUDA 12.x toolkit satisfies a CUDA 12
package, but a CUDA 13 toolkit alone does not. The libraries have to be found through `ldconfig` or
`LD_LIBRARY_PATH` when OFIQ runs, not when it builds. A CUDA toolkit installation is one source; the
`nvidia-*-cu12` wheels that `pip install torch` pulls in are another, in which case the `lib/` folder of
each package under `site-packages/nvidia/` goes on `LD_LIBRARY_PATH`:

```
venv=/path/to/venv/lib/python3.12/site-packages/nvidia
export LD_LIBRARY_PATH=$(ls -d $venv/*/lib | tr '\n' ':')$LD_LIBRARY_PATH
```

The build itself is the Ubuntu build above with `--gpu`, from a virtual environment that holds conan:

```
python3 -m venv /path/to/py_ofiq_env
source /path/to/py_ofiq_env/bin/activate
pip install conan==2.18.1
cd /path/to/OFIQ_Project/scripts
sh build.sh --gpu                                   # -DOFIQ_ORT_GPU_VERSION=<release> to cmake for another release
```

It takes about 11 minutes on a 4-core machine; prefix the last command with `nice -n 19` to leave the
cores to other work. With conan the build cannot be told the ONNX Runtime release from the command line,
so to change it edit the default of `OFIQ_ORT_GPU_VERSION` in `CMakeLists.txt` or run the cmake
configure step from `build.sh` by hand with `-DOFIQ_ORT_GPU_VERSION=<release>`.

The install step copies `libonnxruntime.so.<version>` but not the `libonnxruntime.so.1` link that
its soname names, so the sample application and the Python binding fail with
*"libonnxruntime.so.1: cannot open shared object file"* until the links exist:

```
cd /path/to/OFIQ_Project/install_x86_64_linux/Release
for d in lib bin; do
    ln -sf libonnxruntime.so.1.20.1 $d/libonnxruntime.so.1
    ln -sf libonnxruntime.so.1.20.1 $d/libonnxruntime.so
done
```

To select the provider, copy `data/ofiq_config.jaxn` to `data/ofiq_config_gpu.jaxn` and set
`config.params.execution.provider` to `"cuda"` (see below); the measures are the same as the CPU
build's within rounding, at about 5 times the throughput on an RTX 3090. Check it with the sample
application:

```
cd /path/to/OFIQ_Project/install_x86_64_linux/Release/bin
./OFIQSampleApp -c ../../../data/ofiq_config_gpu.jaxn -i ../../../data/tests/images/b-01-smile.png
```

### Python binding against the GPU build

[python-ofiq](https://github.com/unicef/python-ofiq) (the `ofiq` module on PyPI, whose wheels bundle a
CPU build) compiles against an existing installation when `OFIQ_ROOT` points at it. Build the wheel
from its source once, then install it into any environment with `--no-deps` so pip does not replace it
with the CPU wheel:

```
source /path/to/py_ofiq_env/bin/activate
pip install build scikit-build-core pybind11 ninja numpy
git clone https://github.com/unicef/python-ofiq /path/to/python-ofiq
cd /path/to/python-ofiq
export OFIQ_ROOT=/path/to/OFIQ_Project/install_x86_64_linux/Release
python -m build --wheel --no-isolation --outdir /path/to/OFIQ_Project/dist
pip install --no-deps /path/to/OFIQ_Project/dist/python_ofiq-*.whl
```

The module loads `libofiq_lib.so` and `libonnxruntime.so.1` from `OFIQ_ROOT/lib` by rpath, and the CUDA
libraries through `LD_LIBRARY_PATH` as above, which the dynamic loader reads once when the Python process
starts. `OFIQ(data_dir, config_file)` takes the `data/` folder and `ofiq_config_gpu.jaxn`.

## Configuring GPU Execution Provider

In `data/ofiq_config.jaxn`, configure `config.params.execution`:

```json
"execution": {
  "provider": "auto",
  "device_id": 0,
  "fallback_to_cpu": true
}
```


# Running the sample executable

In this section, we describe how to run the sample application of OFIQ after
compilation.

## Quality assessment for a single facial image

The sample application takes an images and outputs the computed
quality assessments. For example, to output the quality
assessments for one of the conformance test images using OFIQ's configuration (in
<code>./data</code>), run the following commands on Linux.

```
 cd /path/to/OFIQ-Project/install_x86_64_linux/Release/bin/
 ./OFIQSampleApp -c ../../../data/ofiq_config.jaxn -i
        ../../../data/tests/images/b-01-smile.png
```

On Windows run the following commands.

```
 cd C:\Path\To\OFIQ-Project\install_x86_64\Release\bin
 .\OFIQSampleApp -c ..\..\..\data\ofiq_config.jaxn -i
         ..\..\..\data\tests\images\b-01-smile.png
```

## Quality assessment for multiple images

To reproduce the conformance test table given in Annex A of the ISO/IEC 29794-5
international standard for all conformance test images, run the following commands on Linux.

```
 cd /path/to/OFIQ-Project/install_x86_64_linux/Release/bin/
 ./OFIQSampleApp -c ../../../data/ofiq_config.jaxn -i
         ../../../data/tests/images/ -o table.csv
```

The result will be written in the file
`/path/to/OFIQ_Project/install_x86_64_linux/Release/bin/table.csv`.
<br/><br/>
On Windows run the following commands.

```
 cd C:\Path\To\OFIQ-Project\install_x86_64\Release\bin\
 .\OFIQSampleApp -c ..\..\..\data\ -i
          ..\..\..\data\tests\images\ -o table.csv
```

The result will be written in the file
`C:\Path\To\OFIQ-Project\install_x86_64\Release\bin\table.csv``.

## Arguments

The usage pattern of the sample application is the following.

```
 OFIQSampleApp
    -c <directory or file path>
    [-cf <config file name>]
    -i <directory or image file path>
    [-o <csv file path>]
```

The following table documents the usage of the sample application.
<table>
 <tr>
  <td><b>flag</b></td>
  <td><b>argument</b></td>
 </tr>
 <tr>
  <td>-c</td>
  <td>Path to a directory containing the file ofiq_config.jaxn or a path to a JAXN configuration file (see [doc/refman.pdf](doc/refman.pdf)).</td>
 </tr>
 <tr>
  <td>-cf</td>
  <td>Name of the JAXN configuration file contained in the directory specified by the flag -c. Must be omitted if -c specifies a path to a file.</td>
 </tr>
 <tr>
  <td>-i</td>
  <td>Path to a directory containing facial images or a path to a facial image file. If a directory path is specified, all images in PNG and JPEG format will be processed.</td>
 </tr>
 <tr>
  <td>-o</td>
  <td>Path to a CSV file to where the quality assessment is written. If -o is not specified, the output is written to the standard output.</td>
 </tr>
</table>

# Supported platforms

OFIQ compilation has been successfully tested to compile and run on a variety of platforms. The following table gives an overview of platforms that
have been successfully tested by the OFIQ development team.
<table>
 <tr><td><b>platform</b></td><td><b>compiler</b></td><td><b>compiles via building script?</b></td><td><b>remarks</b></td></tr>
 <tr><td>Ubuntu 22.04 (x86_64)</td><td>g++ 11.4.0</td><td>yes</td><td>-</td></tr>
 <tr><td>Ubuntu 24.04 (x86_64)</td><td>g++ 13.2.0</td><td>yes</td><td>-</td></tr>
 <tr><td>Ubuntu 24.04 (Raspberry Pi/ARM64)</td><td>g++ 13.3.0</td><td>yes</td><td>Building script needs specification of the argument <code>--os linux-arm64</code>.</td></tr>
 <tr><td>Windows 10 (x86_64/win64)</td><td>Visual Studio 2019</td><td>yes</td><td>To compile external libraries, i.e., to run compilation without conan, an installation of Visual Studio 2022 was used which was required to build the onnxruntime depency.</td></tr>
 <tr><td>Windows 10 (x86/win32)</td><td>Visual Studio 2019</td><td>yes</td><td>Building script needs specification of the argument <code>--arch x86</code>. To compile external libraries, i.e., to run compilation without conan, an installation of Visual Studio 2022 was used which was required to build the onnxruntime depency.</td></tr>
 <tr><td>MacOS (ARM64)</td><td>clang 15.0.0</td><td>yes</td><td>Building script needs specification of the argument <code>--os macos</code>. </td></tr>
 <tr><td>MacOS (x86_64)</td><td>clang 15.0.0</td><td>yes</td><td>Building script needs specification of the arguments <code>--os macos</code>. Furthermore, see the details on compiling for MacOS (x86_64) above.</td></tr>
 <tr><td>Android</td><td>clang 12.0.8</td><td>no</td><td>Manual compilation including linking of dependencies is required. Not supported by OFIQ's building scripts.</td></tr>
 <tr><td>iOS</td><td>clang 15.0.0</td><td>no</td><td>Manual compilation including linking of dependencies is required. Not supported by OFIQ's building scripts.</td></tr>
</table>
OFIQ may compile on other configurations that have not been tested by the OFIQ development team. Compilation for 32-bit Linux systems, however, were not successful due to the onnxruntime being not supported by 32-bit gcc compiler. Also, compilation on Windows using gcc (for 32- nor 64-bit) did not work since onnxruntime did not build.

# Precompiled binaries

Pre-compiled library binaries are available from [eu-LISA](https://resources.eulisa.europa.eu/research/OFIQ-PrecompiledBinaries.zip).
