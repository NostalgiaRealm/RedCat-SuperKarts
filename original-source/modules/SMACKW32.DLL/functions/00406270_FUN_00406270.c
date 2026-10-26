/*
 * FUN_00406270 at 00406270
 * undefined __stdcall FUN_00406270(void)
 * Address ranges: 00406270-004062ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00406270(void)

{
  int in_EAX;
  undefined4 uVar1;
  
  (*DAT_004104b0)(*(undefined4 *)(in_EAX + 0x38));
  if (*(int *)(in_EAX + 0x48) == 0) {
    if (*(int *)(in_EAX + 0x4c) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 2;
    }
  }
  else if (*(int *)(in_EAX + 0x4c) == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 3;
  }
  (*DAT_00410494)(*(undefined4 *)(in_EAX + 0x38),uVar1,*(int *)(in_EAX + 0x48) != 0);
  (*DAT_00410484)(*(undefined4 *)(in_EAX + 0x38),*(undefined4 *)(in_EAX + 0x40));
  (*DAT_00410490)(*(undefined4 *)(in_EAX + 0x38),0);
  (*DAT_00410488)(*(undefined4 *)(in_EAX + 0x38),0x7f);
  return;
}

