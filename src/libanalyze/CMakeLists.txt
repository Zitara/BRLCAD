# Include directories needed by libanalyze users
set(ANALYZE_INCLUDE_DIRS
  ${BRLCAD_BINARY_DIR}/include
  ${BRLCAD_SOURCE_DIR}/include
  ${BU_INCLUDE_DIRS}
  ${RT_INCLUDE_DIRS}
  ${TCL_INCLUDE_DIRS}
  )
BRLCAD_LIB_INCLUDE_DIRS(analyze ANALYZE_INCLUDE_DIRS "")

set(LIBANALYZE_SOURCES
  api.c
  centroid.c
  density.c
  inside.c
  overlaps.c
  raydiff.c
  #find_subtracted_shapes.cpp
  surf_area.c
  util.cpp
  volume.c
  voxels.c
  MeshHealing/MeshConversion_brlcad.cpp
  MeshHealing/MeshConversion.cpp
  MeshHealing/Zipper.cpp
  MeshHealing/Geometry.cpp
  MeshHealing/Stitch.cpp
  heal_mesh.cpp
  )

set(libanalyze_ignored_files
  MeshHealing/DCEL.h
  MeshHealing/Geometry.h
  MeshHealing/MeshConversion.h
  MeshHealing/MeshConversion_brlcad.h
  MeshHealing/Stitch.h
  MeshHealing/Zipper.h
)
CMAKEFILES(${libanalyze_ignored_files})

BRLCAD_ADDLIB(libanalyze "${LIBANALYZE_SOURCES}" "${TCL_LIBRARY};libbu;librt")
set_target_properties(libanalyze PROPERTIES VERSION 20.0.1 SOVERSION 20)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests)
  add_subdirectory(tests)
endif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests)

CMAKEFILES(analyze_private.h find_subtracted_shapes.cpp)

# Local Variables:
# tab-width: 8
# mode: cmake
# indent-tabs-mode: t
# End:
# ex: shiftwidth=2 tabstop=8
