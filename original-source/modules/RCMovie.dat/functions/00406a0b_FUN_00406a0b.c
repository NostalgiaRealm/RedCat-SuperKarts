/*
 * FUN_00406a0b at 00406a0b
 * int __cdecl FUN_00406a0b(char * param_1, undefined4 param_2, int param_3, int param_4)
 * Address ranges: 00406a0b-00406a84
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00406a0b(char *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int local_8;
  
  local_8 = param_3;
  do {
    if (DAT_0043d414 <= local_8) {
      return -1;
    }
    if ((*(int *)(DAT_0043d420 + 0x30 + local_8 * 0x44) != 0) &&
       (iVar1 = __strcmpi((char *)(DAT_0043d420 + local_8 * 0x44),param_1), iVar1 == 0)) {
      if (param_4 == 0) {
        return local_8;
      }
      iVar1 = FUN_00406327(local_8);
      if (iVar1 == 0) {
        return local_8;
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}

