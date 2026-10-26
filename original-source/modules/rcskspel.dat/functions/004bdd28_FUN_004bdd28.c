/*
 * FUN_004bdd28 at 004bdd28
 * undefined FUN_004bdd28(void)
 * Address ranges: 004bdd28-004bdd7d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004bdd28(int param_1,undefined4 param_2,int param_3)

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
  *(undefined4 *)(param_1 + 0x50) = param_2;
  *(undefined4 *)(param_1 + 0x40) = DAT_006b6a4c;
  uVar1 = DAT_006b6a4c;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  return;
}

