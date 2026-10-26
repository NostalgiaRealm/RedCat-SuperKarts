/*
 * FUN_0048e650 at 0048e650
 * undefined FUN_0048e650(void)
 * Address ranges: 0048e650-0048e739
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0048e650(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_80 [5];
  float local_6c;
  undefined4 local_40 [16];
  
  FUN_004afce0(s_HandleSquashedObject_applying_sq_004fa1b4);
  iVar2 = FUN_0048e630(param_2);
  if (iVar2 != -1) {
    iVar1 = *(int *)(param_2 * 0xd0 + 0xc + DAT_0067ee20);
    if (*(char *)(param_1 + 0x12 + iVar2 * 0x1c) == '\0') {
      FUN_004a09e0();
      FUN_004afce0(s_HandleSquashedObject_o3d_apply_m_004fa1e4);
    }
    iVar1 = iVar1 * 0xa9;
    puVar3 = (undefined4 *)(iVar1 + 0x10 + DAT_006a5c38);
    puVar4 = local_40;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_004a16d0(local_80,local_40);
    local_6c = DAT_0053ba84 * local_6c;
    puVar3 = local_80;
    puVar4 = (undefined4 *)(iVar1 + 0x10 + DAT_006a5c38);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_004afce0(s_HandleSquashedObject_applying_sq_004fa214);
  }
  return;
}

