# FEBasicApplication Example

This repository provides an example of how to use the [FEBasicApplication](https://github.com/Azzinoth/FEBasicApplication/) module in a project. 

## Building the Project

Follow these steps to clone the repository, initialize the submodule, and build the project:

```bash
# Initialize a new Git repository
git init

# Add the remote repository
git remote add origin https://github.com/Azzinoth/FEBasicApplication-Example

# Pull the contents of the remote repository
git pull origin master

# Initialize and update submodules
git submodule update --init --recursive

# Generate the build files using CMake
# Will work in Windows PowerShell
cmake CMakeLists.txt
