/*
 * FUN_00407b2a at 00407b2a
 * undefined4 __cdecl FUN_00407b2a(int param_1, int * param_2, undefined4 param_3, int param_4)
 * Address ranges: 00407b2a-00407c84
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00407b2a(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  char *local_18;
  char *local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  if ((param_4 != -1) && (iVar1 = FUN_00409b18(param_2,param_4,0), iVar1 != 0)) {
    return 0x3e9;
  }
  local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x2c))
                      (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),0,param_3,&local_14,
                       &local_10,&local_18,&local_c,1);
  if (local_8 != 0) {
    FUN_00405af0(local_8);
    FUN_0040187a((byte *)s__s__d____error_locking_sound_buf_00430180);
  }
  if ((local_10 != 0) && (uVar2 = FUN_0041f3be(local_14,local_10,1,param_2), uVar2 != 1)) {
    return 0x3e9;
  }
  if ((local_c != 0) && (uVar2 = FUN_0041f3be(local_18,local_c,1,param_2), uVar2 != 1)) {
    return 0x3e9;
  }
  local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x4c))
                      (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),local_14,local_10,
                       local_18,local_c);
  if (local_8 != 0) {
    FUN_00405af0(local_8);
    FUN_0040187a((byte *)s__s__d____error_unlocking_sound_b_004301bc);
  }
  return 0;
}

