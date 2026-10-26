/*
 * FUN_0041f150 at 0041f150
 * undefined __fastcall FUN_0041f150(int param_1)
 * Address ranges: 0041f150-0041f205
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0041f150(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  iVar1 = param_1 + 0x18;
  puVar3 = (undefined4 *)FUN_0041f0d0(iVar1);
  piVar2 = (int *)*puVar3;
  iVar8 = param_1 + 4;
  iVar7 = *piVar2;
  uVar4 = FUN_0041e8d0(iVar8);
  uVar5 = FUN_0041e8d0(uVar4);
  puVar3 = (undefined4 *)FUN_0041f0d0(iVar8);
  uVar4 = *puVar3;
  uVar6 = FUN_0041e8d0(iVar1);
  uVar6 = FUN_0041e8d0(uVar6);
  iVar7 = (**(code **)(iVar7 + 0x14))(piVar2,uVar6,uVar4,uVar5);
  if (iVar7 < 0) {
    FUN_0041e8d0(iVar1);
    FUN_0041e8d0(iVar1);
    FUN_0041e8d0(iVar1);
    FUN_0041e8d0(iVar1);
    FUN_0041e8d0(iVar8);
    FUN_0041e8d0(iVar8);
    FUN_0041e8d0(iVar8);
    FUN_0041e8d0(iVar8);
    FUN_004015a6((byte *)s_FAILED_rendering_from___d___d____004370a0);
  }
  return;
}

