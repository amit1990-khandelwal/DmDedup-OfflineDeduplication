# DmDedup-OfflineDeduplication
Extended the linux kernel deduplication device mapper DmDedup to support offline deduplicaton. It operates at the block level and is implemented in a modular way. Implementation involved following things: - <br />
o	Three modes to perform off-line deduplication: -<br />
♣	Full (whole disk is scanned and deduplicated);<br />
♣	Incremental (deduplication in increments) and <br />
♣	Bitmap (in-memory bitmap for LBAs and only dirty blocks are de-duplicated in the next cycle).<br />
o	Two ways to trigger it: by kworker thread and by command line interface.
