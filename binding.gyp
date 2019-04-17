{
  "targets": [
    {
      "target_name": "deny_ptrace",
      "sources": ["src/addons/DenyPtrace/DenyPtrace.cpp"],
      "include_dirs": ["<!(node -e \"require('nan')\")"]
    },
    {
             "target_name": "copy_binary",
             "type":"none",
             "dependencies" : [ "deny_ptrace" ],
             "copies":
             [
                {
                   'destination': '<(module_root_dir)/src/build/Release/',
                   'files': ['<(module_root_dir)/build/Release/deny_ptrace.node']
                }
             ]
          }
  ]
}
