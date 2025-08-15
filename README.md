# test

本仓库旨在搭建一个 leetcode 刷题笔记

接下来说明如何在Windows环境中使用VS Code IDE来快速搭建环境

    1.  下载 MSYS2：https://www.msys2.org/
        安装后运行 MSYS2 MSYS（不是 Mingw64）
        更新系统： pacman -Syu
        关闭终端，再打开一次，安装 64 位编译器：pacman -S --needed base-devel mingw-w64-x86_64-toolchain
        把编译器路径加入环境变量：C:\msys64\mingw64\bin
        配置环境变量
        检查是否成功：g++ --version
        如果能看到版本号，就成功了。
    
    
    2.VS Code 的 C/C++ 插件配置设置 includePath: 1.安装 C/C++ 插件（Microsoft 出品的 C/C++ 扩展）
        Windows 推荐安装 MinGW-w64（g++）或 MSVC

    3.创建项目文件夹，假设我们放在：D:\GitHubRepository\test
        在里面新建： mian.cpp
                    .vscode  <----  文件夹，存放VS Code配置文件
        在 .vscode 里新建三个文件：
        3-1 
            c_cpp_properties.json： <----  告诉 VS Code 编译器位置和头文件路径
                {
                    "configurations": [
                        {
                            "name": "Win32",
                            "includePath": [
                                "${workspaceFolder}/**",
                                "C:/msys64/mingw64/include",
                                "C:/msys64/mingw64/x86_64-w64-mingw32/include",
                                "C:/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/13.2.0/include"  # <----  把 13.2.0 改成你电脑实际版本（用 dir C:\msys64\mingw64\lib\gcc\x86_64-w64-mingw32 查看）
                            ],
                            "defines": [],
                            "compilerPath": "C:/msys64/mingw64/bin/g++.exe",
                            "cStandard": "c17",
                            "cppStandard": "c++17",
                            "intelliSenseMode": "windows-gcc-x64"
                        }
                    ],
                    "version": 4
                }
        3-2 
            tasks.json:定义编译任务
                {
                    "version": "2.0.0",
                    "tasks": [
                        {
                            "label": "build cpp",
                            "type": "shell",
                            "command": "g++",
                            "args": [
                                "-std=c++17",
                                "-g",
                                "main.cpp",
                                "-o",
                                "${workspaceFolder}/main.exe"
                            ],
                            "group": {
                                "kind": "build",
                                "isDefault": true
                            },
                            "problemMatcher": ["$gcc"]
                        }
                    ]
                }
        3-3
            launch.json:定义运行任务
                {
                    "version": "0.2.0",
                    "configurations": [
                        {
                            "name": "Run C++",
                            "type": "cppdbg",
                            "request": "launch",
                            "program": "${workspaceFolder}/main.exe",
                            "args": [],
                            "stopAtEntry": false,
                            "cwd": "${workspaceFolder}",
                            "externalConsole": true,
                            "MIMode": "gdb",
                            "miDebuggerPath": "C:/msys64/mingw64/bin/gdb.exe",
                            "preLaunchTask": "build cpp"
                        }
                    ]
                }

    
