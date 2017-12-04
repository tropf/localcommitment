execute_process(
    COMMAND "git" "config" "--system" "alias.gud" "!git commit -m \"\$(localcommitment)\""
    RESULT_VARIABLE git_create_alias)

if(0 EQUAL git_create_alias)
    message("Created git alias!")
else()
    message("Failed to create git alias!")
endif()
