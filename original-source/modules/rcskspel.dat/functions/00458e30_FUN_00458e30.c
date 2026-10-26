/*
 * FUN_00458e30 at 00458e30
 * undefined FUN_00458e30(void)
 * Address ranges: 00458e30-00458e74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00458e30(exception *param_1)

{
  char cVar1;
  int iVar2;
  
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

