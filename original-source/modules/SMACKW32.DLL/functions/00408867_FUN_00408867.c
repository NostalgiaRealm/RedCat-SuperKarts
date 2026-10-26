/*
 * FUN_00408867 at 00408867
 * undefined __stdcall FUN_00408867(void)
 * Address ranges: 00408867-0040888b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408867(void)

{
  int iVar1;
  undefined4 *in_EAX;
  
  if (in_EAX[3] != 0) {
    iVar1 = in_EAX[3] + -1;
    in_EAX[3] = iVar1;
    if (iVar1 == 0) {
      in_EAX[2] = 0;
      ReleaseMutex((HANDLE)*in_EAX);
    }
  }
  return;
}

