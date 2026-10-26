/*
 * FUN_00445c74 at 00445c74
 * undefined __register FUN_00445c74(int * param_1)
 * Address ranges: 00445c74-00445cb6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445c74(int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar3;
  
  piVar1 = FUN_004298bc(param_1);
  if (piVar1 != (int *)0x0) {
    piVar2 = (int *)FUN_00445b3c(param_1,0,CONCAT31((int3)((uint)extraout_ECX >> 8),1),'\0','\x01');
    uVar3 = extraout_ECX_00;
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)FUN_00445b3c(param_1,0,CONCAT31((int3)((uint)extraout_ECX_00 >> 8),1),'\0',
                                   '\0');
      uVar3 = extraout_ECX_01;
    }
    if (piVar2 != (int *)0x0) {
      FUN_0042d2b4(piVar1,piVar2,uVar3);
    }
  }
  return;
}

