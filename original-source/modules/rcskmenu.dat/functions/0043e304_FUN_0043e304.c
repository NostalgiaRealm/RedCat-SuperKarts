/*
 * FUN_0043e304 at 0043e304
 * undefined __register FUN_0043e304(int * param_1)
 * Address ranges: 0043e304-0043e388;0043e390-0043e3a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e304(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  
  if (param_1[0x16] == 0) {
    puStack_10 = (undefined1 *)0x43e31d;
    FUN_00418a10();
  }
  else {
    if (param_1[0x17] == 0) {
      puStack_10 = (undefined1 *)0x43e335;
      piVar1 = (int *)FUN_0040fa70(DAT_0047d7e8);
      puStack_14 = &LAB_0043e389;
      uStack_18 = *in_FS_OFFSET;
      *in_FS_OFFSET = &uStack_18;
      puStack_10 = &stack0xfffffffc;
      if (3 < piVar1[2]) {
        puStack_10 = &stack0xfffffffc;
        FUN_0043e170();
      }
      iVar2 = (**(code **)(*(int *)param_1[0x16] + 0x44))((int *)param_1[0x16],param_1 + 0x18);
      param_1[0x17] = iVar2;
      FUN_0040f504(piVar1,(int)param_1);
      *in_FS_OFFSET = uStack_18;
      puStack_10 = (undefined1 *)0x43e390;
      puStack_14 = (undefined1 *)0x43e388;
      FUN_0040fad4(DAT_0047d7e8);
      return;
    }
    puStack_10 = (undefined1 *)0x43e39e;
    FUN_00418a14(param_1,param_1[0x17]);
    puStack_10 = (undefined1 *)0x43e3a6;
    FUN_0043e3f8((int)param_1);
  }
  return;
}

