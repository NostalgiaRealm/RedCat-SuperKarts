/*
 * FUN_00409535 at 00409535
 * int __cdecl FUN_00409535(uint * param_1)
 * Address ranges: 00409535-004095e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00409535(uint *param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0043d43c == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = FUN_00406ae8(1);
    if (iVar1 == -1) {
      iVar1 = -1;
    }
    else {
      FUN_004015a6((byte *)s_new_3d_buffer_used__d_00430d98);
      iVar2 = FUN_00407c85((LPCSTR)param_1,iVar1);
      if (iVar2 == 0) {
        *(undefined4 *)(DAT_0043d420 + 0x30 + iVar1 * 0x44) = 1;
        FUN_0041f7a0((uint *)(DAT_0043d420 + iVar1 * 0x44),param_1);
        *(int *)(DAT_0043d420 + 0x38 + iVar1 * 0x44) =
             *(int *)(DAT_0043d420 + 0x38 + iVar1 * 0x44) + 1;
      }
      else {
        iVar1 = -1;
      }
    }
  }
  return iVar1;
}

