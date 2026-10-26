/*
 * FUN_004936a0 at 004936a0
 * undefined FUN_004936a0(void)
 * Address ranges: 004936a0-004937d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004936a0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  iVar11 = param_1 * 0xd0 + DAT_0067ee20;
  if (*(code **)(iVar11 + 0x58) != (code *)0x0) {
    (**(code **)(iVar11 + 0x58))(param_1);
    return;
  }
  iVar8 = *(int *)(iVar11 + 0xc) * 0xa9;
  uVar1 = *(undefined4 *)(iVar8 + 0x1c + DAT_006a5c38);
  uVar2 = *(undefined4 *)(iVar8 + 0x2c + DAT_006a5c38);
  uVar3 = *(undefined4 *)(iVar8 + 0x3c + DAT_006a5c38);
  uVar4 = *(undefined4 *)(iVar8 + 0x4c + DAT_006a5c38);
  uVar5 = *(undefined4 *)(iVar8 + 0x48 + DAT_006a5c38);
  uVar6 = *(undefined4 *)(iVar8 + 0x44 + DAT_006a5c38);
  uVar7 = *(undefined4 *)(iVar8 + 0x40 + DAT_006a5c38);
  puVar12 = (undefined4 *)
            (DAT_00680b28 + 0x9c + *(int *)(DAT_0068021c + *(int *)(iVar11 + 0x1c) * 4) * 0x984);
  puVar9 = local_80;
  for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar9 = *puVar12;
    puVar12 = puVar12 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar12 = (undefined4 *)(iVar8 + 0x10 + DAT_006a5c38);
  puVar9 = (undefined4 *)FUN_004a2560(local_40,local_80,puVar12);
  for (iVar11 = 0x10; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar12 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar12 = puVar12 + 1;
  }
  *(undefined4 *)(iVar8 + 0x1c + DAT_006a5c38) = uVar1;
  *(undefined4 *)(iVar8 + 0x2c + DAT_006a5c38) = uVar2;
  *(undefined4 *)(iVar8 + 0x3c + DAT_006a5c38) = uVar3;
  *(undefined4 *)(iVar8 + 0x4c + DAT_006a5c38) = uVar4;
  *(undefined4 *)(iVar8 + 0x48 + DAT_006a5c38) = uVar5;
  *(undefined4 *)(iVar8 + 0x44 + DAT_006a5c38) = uVar6;
  *(undefined4 *)(iVar8 + 0x40 + DAT_006a5c38) = uVar7;
  return;
}

