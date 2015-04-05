museum-telegraph
================

An Arduino driven telegraph simulator

The tap patterns are defined in util/alphabet.txt. The generateMappings.sh script
converts these letter->dot-dash mappings into a c file mapping the character to
a binary encoding. The dot-dash patterns are encoded into an integer by left-shifting
the high/low bit patterns (in reverse). This allows the Arduino application to
extract the high/low bit patterns by right-shifting each bit out of the int until
there are no more bits left in the pattern.
