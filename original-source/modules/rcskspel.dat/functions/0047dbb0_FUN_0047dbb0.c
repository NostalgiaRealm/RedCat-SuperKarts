/*
 * FUN_0047dbb0 at 0047dbb0
 * undefined FUN_0047dbb0(void)
 * Address ranges: 0047dbb0-0047dc8c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0047dbb0(int *param_1)

{
  char cVar1;
  DWORD DVar2;
  uint uVar3;
  undefined4 uStack_14;
  undefined4 uStack_10;
  byte abStack_c [4];
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  FUN_004b9ea0(&uStack_14,&uStack_10,abStack_c);
  uStack_4 = uStack_10;
  uStack_8 = uStack_14;
  cVar1 = FUN_00477890(&uStack_8);
  uVar3 = (uint)(cVar1 != '\0');
  if (((abStack_c[0] & 1) != 0) && (cVar1 != '\0')) {
    uVar3 = 3;
  }
  if (((uVar3 & 1) != 0) && ((*(byte *)(param_1 + 0xd) & 1) == 0)) {
    (**(code **)*param_1)();
  }
  if (((uVar3 & 1) == 0) && ((*(byte *)(param_1 + 0xd) & 1) != 0)) {
    (**(code **)(*param_1 + 4))();
  }
  if (((uVar3 & 2) != 0) && ((*(byte *)(param_1 + 0xd) & 2) == 0)) {
    (**(code **)(*param_1 + 0xc))();
    DVar2 = GetTickCount();
    param_1[0xe] = DVar2;
  }
  if (((uVar3 & 2) == 0) && ((*(byte *)(param_1 + 0xd) & 2) != 0)) {
    (**(code **)(*param_1 + 0x10))();
    DVar2 = GetTickCount();
    if (100 < param_1[0xe] - DVar2) {
      FUN_004afce0(s_ITEM________C_L_I_C_K________004f87b8);
      (**(code **)(*param_1 + 8))();
      param_1[0xe] = 0;
    }
  }
  param_1[0xd] = uVar3;
  return;
}

