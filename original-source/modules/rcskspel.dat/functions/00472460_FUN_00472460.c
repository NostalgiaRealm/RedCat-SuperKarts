/*
 * FUN_00472460 at 00472460
 * undefined FUN_00472460(void)
 * Address ranges: 00472460-0047250a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00472460(int param_1,int param_2)

{
  size_t _Size;
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  FUN_004afce0(s_TGA_create____d__d___004f6ed0,param_1,param_2);
  iVar1 = FUN_00472010();
  if (-1 < iVar1) {
    iVar3 = iVar1 * 0xe;
    _Size = param_1 * param_2 * 3;
    (&DAT_00544bc1)[iVar3] = 0x18;
    *(size_t *)(&DAT_00544bc6 + iVar3) = _Size;
    pvVar2 = _malloc(_Size);
    *(void **)(&DAT_00544bc2 + iVar3) = pvVar2;
    FUN_004afce0(s_try_to_allocate__d_memory_004f6ee8,*(undefined4 *)(&DAT_00544bc6 + iVar3));
    if (*(int *)(&DAT_00544bc2 + iVar3) == 0) {
      FUN_004bffc8(s__s__d___tga_open__Not_enough_mem_004f6f28,
                   s_D__work_rcsk_Code_game_rrrtga_cp_004f6f04,0xec);
      return -1;
    }
    *(short *)(&DAT_00544bca + iVar3) = (short)param_1;
    *(short *)(&DAT_00544bcc + iVar3) = (short)param_2;
    (&DAT_00544bc0)[iVar3] = 1;
  }
  return iVar1;
}

