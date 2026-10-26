/*
 * FUN_00429480 at 00429480
 * undefined FUN_00429480(void)
 * Address ranges: 00429480-004294e8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00429480(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_208 [260];
  undefined1 local_104 [260];
  
  iVar1 = FUN_00443b40(0);
  FUN_004b99c0(&DAT_0053d4ec + iVar1 * 0x100);
  FUN_004b9a00(s__data_004e8648,s_redcat_cmp_004e863c);
  FUN_004afce0(s_init_fileio_004e8650);
  uVar2 = FUN_004b9af0(local_208,&DAT_004e7ba5);
  uVar2 = FUN_004b9af0(local_104,&DAT_004e7b95,uVar2);
  FUN_004b92a0(uVar2);
  return;
}

