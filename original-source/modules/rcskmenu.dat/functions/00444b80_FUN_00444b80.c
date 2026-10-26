/*
 * FUN_00444b80 at 00444b80
 * undefined __register FUN_00444b80(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00444b80-00444bef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00444b80(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  LPCSTR pCVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  UINT UVar3;
  
  if (PTR_DAT_0047c9d8[9] != '\0') {
    uVar1 = FUN_0043fc2c((int)param_1);
    param_3 = extraout_ECX;
    param_2 = extraout_EDX;
    if ((char)uVar1 == '\0') {
      if (*(int *)(*(int *)PTR_DAT_0047c86c + 0x30) != 0) {
        UVar3 = 1;
        pCVar2 = FUN_00403f94(*(undefined **)(*(int *)PTR_DAT_0047c86c + 0x30));
        LoadKeyboardLayoutA(pCVar2,UVar3);
        param_3 = extraout_ECX_01;
        param_2 = extraout_EDX_01;
      }
    }
    else if (*(int *)(*(int *)PTR_DAT_0047c86c + 0x2c) != 0) {
      UVar3 = 1;
      pCVar2 = FUN_00403f94(*(undefined **)(*(int *)PTR_DAT_0047c86c + 0x2c));
      LoadKeyboardLayoutA(pCVar2,UVar3);
      param_3 = extraout_ECX_00;
      param_2 = extraout_EDX_00;
    }
  }
  FUN_00403088(param_1,param_2,param_3);
  return;
}

