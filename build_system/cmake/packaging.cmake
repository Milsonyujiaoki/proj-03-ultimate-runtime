# packaging.cmake — CPack configuration for distributable packages

include_guard(GLOBAL)

function(ur_setup_packaging)
  set(CPACK_PACKAGE_NAME        "${CMAKE_PROJECT_NAME}")
  set(CPACK_PACKAGE_VERSION     "${CMAKE_PROJECT_VERSION}")
  set(CPACK_PACKAGE_VENDOR      "Milson Yuji Aoki")
  set(CPACK_PACKAGE_DESCRIPTION "${CMAKE_PROJECT_DESCRIPTION}")
  set(CPACK_PACKAGE_HOMEPAGE_URL "https://github.com/Milsonyujiaoki/proj-03-ultimate-runtime")
  set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
  set(CPACK_RESOURCE_FILE_README  "${CMAKE_SOURCE_DIR}/README.md")

  # Source package
  set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")
  set(CPACK_SOURCE_IGNORE_FILES
    "/\\.git/"
    "/build/"
    "/\\.vscode/"
    "__pycache__"
    "\\.gitkeep$"
  )

  # Binary packages
  if(WIN32)
    set(CPACK_GENERATOR "ZIP;NSIS")
  elseif(APPLE)
    set(CPACK_GENERATOR "TGZ;DragNDrop")
  else()
    set(CPACK_GENERATOR "TGZ;DEB;RPM")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Milson Yuji Aoki")
    set(CPACK_RPM_PACKAGE_LICENSE "MIT")
  endif()

  set(CPACK_PACKAGE_INSTALL_DIRECTORY "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")
  set(CPACK_STRIP_FILES ON)

  include(CPack)
endfunction()

ur_setup_packaging()
