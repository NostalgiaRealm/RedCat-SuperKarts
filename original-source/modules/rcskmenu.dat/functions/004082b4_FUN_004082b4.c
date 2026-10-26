/*
 * FUN_004082b4 at 004082b4
 * undefined FUN_004082b4(void)
 * Address ranges: 004082b4-00408326
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

BOOL FUN_004082b4(void)

{
  BOOL BVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int extraout_EDX;
  int extraout_EDX_00;
  LPCSTR in_stack_00000004;
  int *in_stack_00000008;
  int *in_stack_0000000c;
  DWORD DStack_14;
  DWORD DStack_10;
  DWORD DStack_c;
  DWORD DStack_8;
  
  if (in_stack_00000004 == (LPCSTR)0x0) {
    in_stack_00000004 = (LPCSTR)0x0;
  }
  BVar1 = GetDiskFreeSpaceA(in_stack_00000004,&DStack_8,&DStack_c,&DStack_10,&DStack_14);
  iVar2 = FUN_00405ce4(DStack_8 * DStack_c,0,extraout_ECX,DStack_10);
  *in_stack_00000008 = iVar2;
  in_stack_00000008[1] = extraout_EDX;
  iVar2 = FUN_00405ce4(DStack_8 * DStack_c,0,in_stack_00000008,DStack_14);
  *in_stack_0000000c = iVar2;
  in_stack_0000000c[1] = extraout_EDX_00;
  return BVar1;
}

