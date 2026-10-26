/*
 * FUN_00408752 at 00408752
 * undefined __stdcall FUN_00408752(void)
 * Address ranges: 00408752-0040877d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408752(void)

{
  undefined4 *in_EAX;
  
  if (in_EAX[1] != 0) {
    CloseHandle((HANDLE)*in_EAX);
  }
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  return;
}

