for fn in cgs_views cgs_ints cgs_events event_to_str cgs__appendi \
          cgs__fmt_spec_extract_length_modifier_ cgs__fmt_spec_star_or_num_or_empty_; do
    objdump -d --no-show-raw-insn --disassemble="$fn" a.out
done > bench.dis
