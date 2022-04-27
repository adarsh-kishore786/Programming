class CreateMicroposts < ActiveRecord::Migration[7.0]
  def change
    create_table :microposts do |t|
      t.text :context
      t.integer :user_id

      t.timestamps
    end
  end
end
