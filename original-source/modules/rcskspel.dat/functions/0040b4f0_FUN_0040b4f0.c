/*
 * FUN_0040b4f0 at 0040b4f0
 * undefined FUN_0040b4f0(void)
 * Address ranges: 0040b4f0-0040b537
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0040b4f0(int param_1,char param_2)

{
  char cVar1;
  int iVar2;
  
  if ((param_2 != '\0') && (iVar2 = *(int *)(param_1 + 4), iVar2 != 0)) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

