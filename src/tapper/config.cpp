//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "config.h"

const int DOT_LENGTH = 150; //ms
const int INTER_LETTER_BREAK = 1*DOT_LENGTH;
const int INTER_WORD_BREAK = 2*DOT_LENGTH;

const int MESSAGES_COUNT = 1;
String Messages[] {
  "... --- ...|... --- ...|... --- ..."
};
/*
const int MAPPER_LENGTH = 54;
Mapping morseMappings[] = {
  {":-", "KX"}, //colon dash
  {"-", "HX"}, //hyphen
  {"/fraction1/", "E"}, //fraction line
  {"/fraction2/", "UT"}, //fraction line
  {"/cents/", "C"}, //cents
  {"/pounds/", "LX"}, //pounds
  {"/shillings/", "UT"}, //shillings
  {"/pence/", "D"}, //pence
  {"/capital/", "CX"}, //capital letter
  {"/small/", "I5"}, //small letter
  {"/dot/", "DOT"}, //decimal point
  {"/notcode/", "E5"}, //not code
  {"/underline/", "UX"}, //underline
  {"/endline/", "UJ"}, //underline (end)
  {"/brackets/", "BX"}, //brackets
  {"/quote/", "QN"}, //quotation (start)
  {"/endquote/", "QJ"}, //quotation (end)
  {"/repeat/", "DN"}, //repeat when sending
  {"/understood/", "13"}, //I understand
  {"/broadcast/", "23"}, //message to all offices
  {"/busy/", "25"}, //I am busy
  {"/break/", "BK"}, //break or stop sending
  {"/finish/", "30"}, //finish (no more)
  {"/regards/", "73"}, //regards
  {"/paragraph/", "----"}, //paragraph
  {":\"", "KQ"}, //colon quotation?
  {";", "SI"}, //semicolon
  {"=", "BK"}, //double dash
  {"'", "QX"}, //apostrophe
  {"&", "ES"},
  {"$", "SX"}, //dollars
  {"%", "OSO"}, //percent
  {",", ".-.-"}, //comma
  {"?", "-..-." }, //interrogation
  {"!", "---."}, //exclamation
  {"(", "PN"}, //parenthesis (start)
  {")", "PY"}, //parenthesis (end)
  {":", "KO"}, //colon
  {"/", "..--"},
  {".", "..--.."}, //period
  {"A", ".-"},
  {"B", "-..."},
  {"C", ".. ."},
  {"D", "-.."},
  {"E", "."},
  {"F", ".-."},
  {"G", "--."},
  {"H", "...."},
  {"I", ".."},
  {"J", "-.-."},
  {"K", "-.-"},
  {"L", "2-"},
  {"M", "--"},
  {"N", "-."},
//  {"O", ". ."},
  {"O", "---"},
  {"P", "....."},
  {"Q", "..-."},
  {"R", ". .."},
  {"S", "..."},
  {"T", "-"},
  {"U", "..-"},
  {"V", "...-"},
  {"W", ".--"},
  {"X", ".-.."},
  {"Y", ".. .."},
  {"Z", "... ."},
  {"1", ".--."},
  {"2", "..-.."},
  {"3", "...-."},
  {"4", "....-"},
  {"5", "---"},
  {"6", "......"},
  {"7", "--.."},
  {"8", "-...."},
  {"9", "-..-"},
  {"0", "3-"}//"3-" but some docs say ". ."
};
*/
