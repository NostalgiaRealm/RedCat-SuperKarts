/*
 * FUN_0048f150 at 0048f150
 * undefined FUN_0048f150(void)
 * Address ranges: 0048f150-0048f256
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048f150(void)

{
  int iVar1;
  int iVar2;
  
  DAT_0067ec34 = 0;
  _strncpy(&DAT_0067ec3c,s_g_elapsed_buffer_004fa384,0x19);
  _strncpy(&DAT_0067ec55,s_float_004fa37c,0x19);
  if (DAT_0067ec34 != 0) {
    if (DAT_0067ec34 == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_0067ec55,&DAT_0067ec3c,
                   DAT_0067ec2c);
      FUN_004bc150(DAT_0067ec28);
    }
    if (DAT_0067ec34 != 0) {
      FUN_004bc150(DAT_0067ec38);
      DAT_0067ec34 = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_0067ec28 = operator_new(0x10);
  DAT_0067ec2c = 4;
  _DAT_0067ec30 = 0;
  DAT_0067ec38 = operator_new(4);
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,&DAT_0067ec55,&DAT_0067ec3c,DAT_0067ec2c)
  ;
  DAT_0067ec34 = 1;
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    *(undefined1 *)((int)DAT_0067ec38 + iVar1) = 0;
    iVar1 = iVar2;
  } while (iVar2 < 4);
  FUN_004be654(&LAB_0048f260);
  return;
}

