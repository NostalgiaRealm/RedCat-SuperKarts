/*
 * FUN_004090a6 at 004090a6
 * undefined4 __fastcall FUN_004090a6(undefined4 param_1, int param_2)
 * Address ranges: 004090a6-00409106
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_004090a6(undefined4 param_1,int param_2)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  (*(code *)PTR_FUN_0040ef70)();
  iVar1 = FUN_0040917a(1,0x10);
  if (iVar1 != 0) {
    uVar3 = FUN_00409405();
    puVar2 = (undefined4 *)((ulonglong)uVar3 >> 0x20);
    if ((int)uVar3 == 0) {
      puVar2[2] = param_2;
      puVar2[1] = in_EAX;
      puVar2[3] = (uint)*(byte *)(param_2 + 0x52);
      *puVar2 = DAT_00410a4c;
      DAT_00410a4c = puVar2;
    }
    else {
      FUN_0040650f();
    }
  }
  (*(code *)PTR_FUN_0040ef74)();
  return extraout_ECX;
}

