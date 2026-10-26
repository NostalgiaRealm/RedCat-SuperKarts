/*
 * FUN_00432aa0 at 00432aa0
 * undefined __register FUN_00432aa0(undefined4 param_1, uint param_2)
 * Address ranges: 00432aa0-00432ad8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00432aa0(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_004301d8(DAT_0047d774);
  if (-1 < iVar1 + -1) {
    iVar3 = 0;
    do {
      uVar4 = 0;
      iVar2 = FUN_004301c4(DAT_0047d774,iVar3);
      FUN_004405f0(iVar2,param_2 & 0xffff,0,uVar4);
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

