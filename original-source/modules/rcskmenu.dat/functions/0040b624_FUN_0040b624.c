/*
 * FUN_0040b624 at 0040b624
 * undefined __register FUN_0040b624(int param_1, int param_2, int * param_3, int * param_4)
 * Address ranges: 0040b624-0040b696
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040b624(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = FUN_00403dd0(param_1);
  iVar4 = 1;
  iVar2 = 1;
  while ((iVar2 < iVar1 && (iVar4 < param_2))) {
    iVar4 = iVar4 + 1;
    uVar3 = (uint)*(byte *)(param_1 + -1 + iVar2);
    if (((byte)(&DAT_0047b114)[(int)uVar3 >> 3] >> (uVar3 & 7) & 1) != 0) {
      iVar2 = iVar2 + 1;
    }
    iVar2 = iVar2 + 1;
  }
  if (((iVar4 == param_2) && (iVar2 < iVar1)) &&
     (uVar3 = (uint)*(byte *)(param_1 + -1 + iVar2),
     ((byte)(&DAT_0047b114)[(int)uVar3 >> 3] >> (uVar3 & 7) & 1) != 0)) {
    iVar2 = iVar2 + 1;
  }
  *param_3 = iVar4;
  *param_4 = iVar2;
  return;
}

