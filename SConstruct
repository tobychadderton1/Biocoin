PROGRAM_NAME = "LD45"

SFML_PATH = "C:/SFML"

libs = """
sfml-graphics
sfml-window
sfml-system
sfml-audio
"""

env = Environment(
    LIBPATH=[f"{SFML_PATH}/lib"],
    CPPPATH=[f"{SFML_PATH}/include", "include"],
    LIBS = libs.split("\n"),
    TARGET_ARCH='x86'
)

env.Program(f"build/{PROGRAM_NAME}", Glob("src/*.cpp"))