if is_plat("windows") then
    add_cxxflags("cl::/std:c++23preview", {force = true})
else
    set_languages("c++23")
end

add_rules("mode.debug", "mode.release")

target("rando")
    set_kind("binary")
    add_files("src/*.cpp")