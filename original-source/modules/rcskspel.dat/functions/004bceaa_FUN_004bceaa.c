/*
 * FUN_004bceaa at 004bceaa
 * undefined FUN_004bceaa(void)
 * Address ranges: 004bceaa-004bcf21
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004bceaa(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  *(bool *)(param_1 + 0x48) = param_3 == 1;
  if (param_3 == 0) {
    std::locale::~locale((locale *)(param_1 + 0x4c));
    if ((locale *)(param_1 + 0x4c) != (locale *)0x0) {
      FUN_004bc7cd();
    }
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  FUN_004bdd7e();
  if ((param_2 != 0) && (*(char *)(param_1 + 0x48) == '\0')) {
    *(int *)(param_1 + 0x1c) = param_2;
    *(int *)(param_1 + 0xc) = param_2 + 8;
    *(int *)(param_1 + 0x10) = param_2 + 8;
    *(int *)(param_1 + 0x20) = param_2;
    *(int *)(param_1 + 0x2c) = param_2 + 4;
    *(int *)(param_1 + 0x30) = param_2 + 4;
  }
  *(int *)(param_1 + 0x50) = param_2;
  *(undefined4 *)(param_1 + 0x40) = DAT_006b6a50;
  uVar1 = DAT_006b6a50;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  return;
}

