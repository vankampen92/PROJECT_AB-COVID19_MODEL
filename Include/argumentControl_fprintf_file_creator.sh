cp *argumentControl.c ../
rename -f 's/argumentControl.c/argumentControl_fprintf.c/' *
find . -name "*argumentControl_fprintf.c" -exec sh argumentControl_replace_key_words.sh {} \;
### mv ../*argumentControl.c .
