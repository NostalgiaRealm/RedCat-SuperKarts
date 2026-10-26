/*
 * FUN_0043a9b0 at 0043a9b0
 * undefined __register FUN_0043a9b0(int param_1, int * param_2)
 * Address ranges: 0043a9b0-0043aa12
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043a9b0(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  FUN_00403b50(param_2);
  iVar3 = 1;
  iVar1 = FUN_00403dd0(param_1);
  if (0 < iVar1) {
    do {
      uVar2 = (uint)*(byte *)(param_1 + -1 + iVar3);
      if (((byte)PTR_DAT_0047c9c8[(int)uVar2 >> 3] >> (uVar2 & 7) & 1) == 0) {
        if (((*(char *)(param_1 + -1 + iVar3) == '&') && (0 < iVar1 - iVar3)) &&
           (iVar3 = iVar3 + 1, *(char *)(param_1 + -1 + iVar3) != '&')) {
          FUN_00403cf8(param_2,(uint)*(byte *)(param_1 + -1 + iVar3));
        }
      }
      else {
        iVar3 = iVar3 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= iVar1);
  }
  return;
}

