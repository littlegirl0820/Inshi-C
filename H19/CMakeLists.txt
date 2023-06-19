aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCES)

foreach(source_file ${SOURCES})
    get_filename_component(file_name ${source_file} NAME_WE)
    add_executable(${file_name} ${source_file})
endforeach()
