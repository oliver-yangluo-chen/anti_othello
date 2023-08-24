make

# Edit these
W="./captain_random.py"
B="./captain_random.py"

# Examples to run something other than random-versus-random:
#W="java JavaBot"
#W="./CppBot"
#W="./py_bot.py"
#W="python3 py_bot.py"  <- This doesn't require chmod/shebang

./run_game.py "$B" "$W"