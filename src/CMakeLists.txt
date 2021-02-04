# created on 2021/1/31
# author @zoloypzuo

# ---------------------------------------------------
# third party
# ---------------------------------------------------
add_subdirectory(bullet_collision)
add_subdirectory(bullet_dynamics)
add_subdirectory(bullet_linearmath)
add_subdirectory(detour)
add_subdirectory(freeimage)
add_subdirectory(freetype)
add_subdirectory(gorilla_audio)
add_subdirectory(libjpeg)
add_subdirectory(libogg)
add_subdirectory(libopenjpeg)
add_subdirectory(libpng)
add_subdirectory(libraw)
add_subdirectory(libtiff4)
add_subdirectory(libvorbis)
add_subdirectory(lua)
add_subdirectory(ogre3d)
add_subdirectory(ogre3d_direct3d9)
add_subdirectory(ogre3d_gorilla)
add_subdirectory(ogre3d_particlefx)
add_subdirectory(ogre3d_procedural)
add_subdirectory(ois)
add_subdirectory(openexr)
add_subdirectory(opensteer)
add_subdirectory(recast)
add_subdirectory(zlib)
add_subdirectory(zzip)
# ---------------------------------------------------
# framework
# ---------------------------------------------------
add_subdirectory(demo_framework)
include_directories(demo_framework/include)
link_directories(demo_framework)
# ---------------------------------------------------
# games
# ---------------------------------------------------
add_subdirectory(demo_framework_test)
#add_subdirectory(chapter_1_introduction)
#add_subdirectory(chapter_2_movement)
#add_subdirectory(chapter_3_animation)
#add_subdirectory(chapter_4_mind_body)
#add_subdirectory(chapter_5_navigation)
#add_subdirectory(chapter_6_decision_making)
#add_subdirectory(chapter_7_knowledge)
#add_subdirectory(chapter_8_perception)
add_subdirectory(chapter_9_tactics)
