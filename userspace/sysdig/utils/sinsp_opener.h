/*
Copyright (C) 2013-2022 Sysdig Inc.

This file is part of sysdig.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/
#pragma once

#include <sinsp.h>

#include <string>

struct sinsp_opener
{
    sinsp_opener():
        mode_udig(false),
        mode_bpf(false),
        mode_gvisor(false),
        mode_plugin(false),
        mode_savefile(false),
        enable_print_progress(false),
        enable_page_faults(false) { }
    virtual ~sinsp_opener() = default;
	sinsp_opener(sinsp_opener&&) = default;
	sinsp_opener& operator = (sinsp_opener&&) = default;
	sinsp_opener(const sinsp_opener&) = default;
	sinsp_opener& operator = (const sinsp_opener&) = default;
    
    void open(sinsp* inspector) const;

    bool mode_udig;
    bool mode_bpf;
    bool mode_gvisor;
    bool mode_plugin;
    bool mode_savefile;
    bool enable_print_progress;
    bool enable_page_faults;
    std::string bpf_probe;
    std::string savefile_path;
    std::string plugin_name;
    std::string plugin_params;
    std::string gvisor_config;
    std::string gvisor_root;
};