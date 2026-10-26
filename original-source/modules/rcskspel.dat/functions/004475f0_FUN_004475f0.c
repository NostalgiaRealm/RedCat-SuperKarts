/*
 * FUN_004475f0 at 004475f0
 * undefined FUN_004475f0(void)
 * Address ranges: 004475f0-0044763a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004475f0(exception *param_1)

{
  char cVar1;
  int iVar2;
  
  *(undefined ***)param_1 = &PTR_FUN_004d34f4;
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  exception::~exception(param_1);
  return;
}

