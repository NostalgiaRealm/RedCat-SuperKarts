/*
 * FUN_004083d0 at 004083d0
 * char * __register FUN_004083d0(char * param_1, char * param_2, int param_3)
 * Address ranges: 004083d0-00408400
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char * FUN_004083d0(char *param_1,char *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  bool bVar4;
  
  bVar4 = param_3 == 0;
  iVar1 = param_3;
  pcVar3 = param_2;
  if (!bVar4) {
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar3 == '\0';
      pcVar3 = pcVar3 + 1;
    } while (!bVar4);
    if (bVar4) {
      iVar1 = iVar1 + 1;
    }
  }
  pcVar3 = param_1;
  for (uVar2 = (uint)(param_3 - iVar1) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)param_2;
    param_2 = param_2 + 4;
    pcVar3 = pcVar3 + 4;
  }
  for (uVar2 = param_3 - iVar1 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar3 = *param_2;
    param_2 = param_2 + 1;
    pcVar3 = pcVar3 + 1;
  }
  *pcVar3 = '\0';
  return param_1;
}

