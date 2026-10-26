/*
 * FUN_00489d20 at 00489d20
 * undefined FUN_00489d20(void)
 * Address ranges: 00489d20-00489e18
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00489d20(int param_1)

{
  int iVar1;
  float local_8;
  undefined4 local_4;
  
  if (*(char *)(param_1 + 0xec) != '\0') {
    iVar1 = FUN_004b3830(0x67);
    if (iVar1 != 0) {
      *(bool *)(param_1 + 0x100) = *(char *)(param_1 + 0x100) == '\0';
      FUN_004893d0(0x67);
    }
    iVar1 = FUN_004b3830(0x68);
    if (iVar1 != 0) {
      iVar1 = *(int *)(param_1 + 0xfc) + 1;
      *(int *)(param_1 + 0xfc) = iVar1;
      if (iVar1 == 6) {
        *(undefined4 *)(param_1 + 0xfc) = 0;
      }
      FUN_004893d0(0x68);
    }
    iVar1 = FUN_004b3830(0x69);
    if (iVar1 != 0) {
      *(bool *)(param_1 + 0x101) = *(char *)(param_1 + 0x101) == '\0';
      FUN_004893d0(0x69);
    }
    if (*(int *)(param_1 + 0xe8) == DAT_0053be28) {
      local_4 = DAT_0053bd74;
      local_8 = (float)DAT_0053be34 * 0.01;
      if (local_8 <= 0.0) {
        return;
      }
    }
    else {
      local_8 = 0.5;
      local_4 = 0x3f000000;
    }
    FUN_00489c70(local_4,local_8);
  }
  return;
}

