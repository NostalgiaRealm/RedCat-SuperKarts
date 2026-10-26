/*
 * FUN_0046bb20 at 0046bb20
 * undefined FUN_0046bb20(void)
 * Address ranges: 0046bb20-0046bb64
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046bb20(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x44);
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  FUN_004662d0();
  return;
}

