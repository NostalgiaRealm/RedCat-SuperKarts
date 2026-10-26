/*
 * FUN_0043155c at 0043155c
 * undefined4 __register FUN_0043155c(int param_1, int * param_2)
 * Address ranges: 0043155c-004315aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043155c(int param_1,int *param_2)

{
  if (*param_2 == 0x1a) {
    if (*(char *)(param_1 + 0x49) != '\0') {
      SetThreadLocale(0x400);
      FUN_0040b9e0();
    }
    if (*(char *)(param_1 + 0x4a) != '\0') {
      FUN_004306c0(DAT_0047d774);
      if (*(char *)(param_1 + 0x78) != '\0') {
        FUN_0043286c(param_1,'\0');
        FUN_0043286c(param_1,'\x01');
      }
    }
  }
  return 0;
}

