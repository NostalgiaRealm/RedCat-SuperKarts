/*
 * FUN_004501e0 at 004501e0
 * undefined FUN_004501e0(void)
 * Address ranges: 004501e0-004502c1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_004501e0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(int *)(param_1 + 0xc) != -1) {
    local_1c = s_Object_already_created_004f1114;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&local_1c,&DAT_004d5538);
  }
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  uVar2 = FUN_0048fc70(0,0,0,0,0,0,0,0,0,0,0,0);
  *(undefined4 *)(param_1 + 0xc) = uVar2;
  FUN_004932e0(uVar2);
  iVar1 = *(int *)(*(int *)(param_1 + 0xc) * 0xd0 + 0xc + DAT_0067ee20);
  *(int *)(param_1 + 8) = iVar1;
  *(undefined4 *)(DAT_006a5c38 + iVar1 * 0xa9 + 0xa1) = 2;
  return *(undefined4 *)(param_1 + 0xc);
}

