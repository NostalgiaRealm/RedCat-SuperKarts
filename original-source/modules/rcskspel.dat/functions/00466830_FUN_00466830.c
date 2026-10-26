/*
 * FUN_00466830 at 00466830
 * undefined FUN_00466830(void)
 * Address ranges: 00466830-00466987;004669b9-004669c9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00466830(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  float local_24;
  float local_20;
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004cf9b5;
  local_10 = ExceptionList;
  local_14 = &stack0xffffffd0;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_00466a20();
  if (DAT_00544af4 != '\0') {
    FUN_00466ca0();
  }
  local_1c = 0;
  local_24 = _DAT_0053be44 * *(float *)(param_1 + 0x30) + *(float *)(param_1 + 0x34);
  local_20 = DAT_0053be4c * *(float *)(param_1 + 0x38) + *(float *)(param_1 + 0x3c);
  FUN_004669d0(&local_24);
  FUN_00458400(&local_24);
  for (iVar3 = 0; iVar3 < DAT_00508610; iVar3 = iVar3 + 1) {
    cVar1 = FUN_00417e90(iVar3);
    iVar2 = DAT_0053be28;
    if (cVar1 == '\0') {
      iVar2 = (&DAT_005081bc)[iVar3 * 0x1c];
    }
    local_24 = *(float *)(DAT_006a5c38 + *(int *)(iVar2 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + 0x50)
               * *(float *)(param_1 + 0x30) + *(float *)(param_1 + 0x34);
    cVar1 = FUN_00417e90(iVar3);
    iVar2 = DAT_0053be28;
    if (cVar1 == '\0') {
      iVar2 = (&DAT_005081bc)[iVar3 * 0x1c];
    }
    local_20 = *(float *)(DAT_006a5c38 + *(int *)(iVar2 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + 0x58)
               * *(float *)(param_1 + 0x38) + *(float *)(param_1 + 0x3c);
    FUN_004669d0(&local_24);
    FUN_00458400(&local_24);
  }
  ExceptionList = local_10;
  return;
}

