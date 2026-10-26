/*
 * FUN_0041202c at 0041202c
 * bool __register FUN_0041202c(int param_1)
 * Address ranges: 0041202c-00412072
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_0041202c(int param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = *(char **)(param_1 + 0x14);
  for (pcVar3 = pcVar2; (*pcVar3 != '\0' && (*pcVar3 != '.')); pcVar3 = pcVar3 + 1) {
  }
  cVar1 = *pcVar3;
  if (cVar1 != '\0') {
    FUN_00403c38((int *)(param_1 + 0x10),(undefined4 *)pcVar2,(int)pcVar3 - (int)pcVar2);
    FUN_00404018((int *)(param_1 + 0x14),1,((int)pcVar3 - (int)pcVar2) + 1);
  }
  return cVar1 != '\0';
}

