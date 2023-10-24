import os
import subprocess
import argparse

parser = argparse.ArgumentParser(description='Build dependencies')
parser.add_argument('workdir')
parser.add_argument('outdir')
args = parser.parse_args()

print('Build USD library')

vsvars='"c:/Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/Build/vcvars64.bat"'

rootdir   = os.path.dirname(os.path.realpath(__file__))
build_script = os.path.join(rootdir, 'ThirdParty', 'OpenUSD', 'build_scripts', 'build_usd.py')
builddir  = os.path.join(args.workdir, 'build')
downloads = os.path.join(args.workdir, 'downloads')
libdir    = os.path.join(args.workdir, 'libs')

command = ['python', build_script, 
           '--build', builddir, 
           '--src', downloads, 
           '--inst', libdir,
           '--build-variant', 'relwithdebuginfo',
           '--build-monolithic', '--no-tests',
           '--no-examples', '--no-tutorials', 
           '--no-docs', '--no-python-docs', 
           '--no-tools', '--python', 
           '--no-openimageio',         
           '--no-usdview', '--materialx', 
           args.outdir]

# Execute the command in the shell
try:

    os.system(vsvars + " & " + " ".join(command))

except subprocess.CalledProcessError as e:
    # Handle errors if the command fails
    print("Error executing command:", e)