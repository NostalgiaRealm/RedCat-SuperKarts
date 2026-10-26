/*
 * FUN_0043b580 at 0043b580
 * undefined FUN_0043b580(void)
 * Address ranges: 0043b580-0043b5ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043b580(char *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  
  cVar2 = *param_1;
  if (cVar2 == *param_2) {
    pcVar3 = param_1;
    do {
      if (cVar2 == '\0') {
        return 1;
      }
      cVar2 = pcVar3[1];
      pcVar1 = pcVar3 + (int)(param_2 + (1 - (int)param_1));
      pcVar3 = pcVar3 + 1;
    } while (cVar2 == *pcVar1);
  }
  return 0;
}

