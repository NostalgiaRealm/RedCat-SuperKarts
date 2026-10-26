/*
 * FUN_0048ea90 at 0048ea90
 * undefined FUN_0048ea90(void)
 * Address ranges: 0048ea90-0048eb63
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0048ea90(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  bool bVar8;
  undefined4 local_40 [16];
  
  iVar1 = param_1 + param_2 * 0x1c;
  iVar2 = *(int *)(*(int *)(param_1 + param_2 * 0x1c) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9;
  puVar6 = (undefined4 *)(DAT_006a5c38 + 0x10 + iVar2);
  puVar7 = local_40;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  uVar5 = *(uint *)(iVar1 + 0xc) & 0x80000001;
  bVar8 = uVar5 == 0;
  if ((int)uVar5 < 0) {
    bVar8 = (uVar5 - 1 | 0xfffffffe) == 0xffffffff;
  }
  if (bVar8) {
    uVar3 = __ftol(local_40);
  }
  else {
    uVar3 = __ftol(local_40);
  }
  FUN_004a16f0(local_40,uVar3);
  puVar6 = local_40;
  puVar7 = (undefined4 *)(DAT_006a5c38 + 0x10 + iVar2);
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  if (*(int *)(iVar1 + 0xc) == 3) {
    *(undefined4 *)(iVar1 + 0xc) = 0;
    return;
  }
  *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 1;
  return;
}

