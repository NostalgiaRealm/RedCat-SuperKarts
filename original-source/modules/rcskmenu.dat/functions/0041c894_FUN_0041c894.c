/*
 * FUN_0041c894 at 0041c894
 * undefined __register FUN_0041c894(int * param_1, int * param_2)
 * Address ranges: 0041c894-0041c94b;0041c973-0041c982
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041c894(int *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffff84;
  undefined4 uStack_70;
  undefined1 *puStack_6c;
  undefined4 local_5c [21];
  int *local_8;
  
  local_8 = param_1;
  if (param_2 != (int *)0x0) {
    uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_00416860);
    if ((char)uVar1 == '\0') {
      FUN_0040fca8(local_8,param_2);
      return;
    }
  }
  puStack_6c = (undefined1 *)0x41c8c4;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0047d698);
  puStack_6c = &LAB_0041c94c;
  uStack_70 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_70;
  if (param_2 == (int *)0x0) {
    FUN_00402b54(local_5c,0x54,0);
    in_stack_ffffff84 = 0;
    FUN_0041d1c4((int)local_8,0,0,(int *)0x0,0,local_5c);
  }
  else {
    FUN_0041bd50(param_2[8]);
    FUN_0041bd54((int *)local_8[8]);
    local_8[8] = param_2[8];
    *(undefined1 *)((int)local_8 + 0x19) = *(undefined1 *)((int)param_2 + 0x19);
    local_8[0xb] = param_2[0xb];
    *(char *)(local_8 + 0xc) = (char)param_2[0xc];
  }
  *in_FS_OFFSET = in_stack_ffffff84;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0047d698);
  return;
}

